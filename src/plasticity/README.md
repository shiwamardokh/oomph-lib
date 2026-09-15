# plasticity

Finite-strain plasticity **elements**. Interpolate displacement, form the
deformation gradient F at each Gauss point, call the constitutive law in
`plasticity_constitutive/`, and assemble the residual and Jacobian.

The element carries the per-Gauss-point state as an opaque, model-sized bundle
and never interprets it. It meets the constitutive layer only at:

    compute_response(F, state_n) -> (stress, state_np1, tangent)
